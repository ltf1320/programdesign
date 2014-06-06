﻿function ManageViewModel(app, dataModel) {
    var self = this,
        startedLoad = false;

    // UI state used by private state
    self.logins = ko.observableArray();

    // Private state
    self.hasLocalPassword = ko.computed(function () {
        var logins = self.logins();

        for (var i = 0; i < logins.length; i++) {
            if (logins[i].loginProvider() === self.localLoginProvider()) {
                return true;
            }
        }

        return false;
    });

    // Data
    self.userName = ko.observable();
    self.localLoginProvider = ko.observable();

    // UI state
    self.externalLoginProviders = ko.observableArray();
    self.loading = ko.observable(true);
    self.message = ko.observable();
    self.errors = ko.observableArray();

    self.changePassword = ko.computed(function () {
        if (!self.hasLocalPassword()) {
            return null;
        }

        return new ChangePasswordViewModel(app, self, self.userName(), dataModel);
    });

    self.setPassword = ko.computed(function () {
        if (self.hasLocalPassword()) {
            return null;
        }

        return new SetPasswordViewModel(app, self, dataModel);
    });

    self.hasExternalLogin = ko.computed(function () {
        return self.externalLoginProviders().length > 0;
    });

    self.canRemoveLogin = ko.computed(function () {
        return self.logins().length > 1;
    });

    // Operations
    self.load = function () { // Load user management data
        if (!startedLoad) {
            startedLoad = true;

            dataModel.getManageInfo(dataModel.returnUrl, true /* generateState */)
                .done(function (data) {
                    if (typeof (data.localLoginProvider) !== "undefined" &&
                        typeof (data.userName) !== "undefined" &&
                        typeof (data.logins) !== "undefined" &&
                        typeof (data.externalLoginProviders) !== "undefined") {
                        self.userName(data.userName);
                        self.localLoginProvider(data.localLoginProvider);

                        for (var i = 0; i < data.logins.length; i++) {
                            self.logins.push(new RemoveLoginViewModel(data.logins[i], self, dataModel));
                        }

                        for (var i = 0; i < data.externalLoginProviders.length; i++) {
                            self.externalLoginProviders.push(new AddExternalLoginProviderViewModel(app,
                                data.externalLoginProviders[i]));
                        }
                    } else {
                        app.errors.push("检索用户信息时出错。");
                    }

                    self.loading(false);
                }).failJSON(function (data) {
                    var errors;

                    self.loading(false);
                    errors = dataModel.toErrorsArray(data);

                    if (errors) {
                        app.errors(errors);
                    } else {
                        app.errors.push("检索用户信息时出错。");
                    }
                });
        }
    }

    self.home = function () {
        app.navigateToHome();
    };

    self.addExternalLogin = function (externalAccessToken, externalError) {
        if (externalError !== null || externalAccessToken === null) {
            self.errors.push("无法关联外部登录名。");
            self.load();
        } else {
            dataModel.addExternalLogin({
                externalAccessToken: externalAccessToken
            }).done(function (data) {
                self.load();
            }).failJSON(function (data) {
                var errors = dataModel.toErrorsArray(data);

                if (errors) {
                    self.errors(errors);
                } else {
                    self.errors.push("出现未知错误。");
                }

                self.load();
            });
        }
    };
}

function AddExternalLoginProviderViewModel(app, data) {
    var self = this;

    // Data
    self.name = ko.observable(data.name);

    // Operations
    self.login = function () {
        sessionStorage["state"] = data.state;
        sessionStorage["associatingExternalLogin"] = true;
        // IE doesn't reliably persist sessionStorage when navigating to another URL. Move sessionStorage temporarily
        // to localStorage to work around this problem.
        app.archiveSessionStorageToLocalStorage();
        window.location = data.url;
    };
}

function ChangePasswordViewModel(app, parent, name, dataModel) {
    var self = this;

    // Private operations
    function reset() {
        self.errors.removeAll();
        self.oldPassword(null);
        self.newPassword(null);
        self.confirmPassword(null);
        self.changing(false);
        self.validationErrors.showAllMessages(false);
    }

    // Data
    self.name = ko.observable(name);
    self.oldPassword = ko.observable("").extend({ required: true });
    self.newPassword = ko.observable("").extend({ required: true });
    self.confirmPassword = ko.observable("").extend({ required: true, equal: self.newPassword });

    // Other UI state
    self.changing = ko.observable(false);
    self.errors = ko.observableArray();
    self.validationErrors = ko.validation.group([self.oldPassword, self.newPassword, self.confirmPassword]);

    // Operations
    self.change = function () {
        self.errors.removeAll();
        if (self.validationErrors().length > 0) {
            self.validationErrors.showAllMessages();
            return;
        }
        self.changing(true);

        dataModel.changePassword({
            oldPassword: self.oldPassword(),
            newPassword: self.newPassword(),
            confirmPassword: self.confirmPassword()
        }).done(function (data) {
            self.changing(false);
            reset();
            parent.message("你的密码已更改。");
        }).failJSON(function (data) {
            var errors;

            self.changing(false);
            errors = dataModel.toErrorsArray(data);

            if (errors) {
                self.errors(errors);
            } else {
                self.errors.push("出现未知错误。");
            }
        });
    };
}

function RemoveLoginViewModel(data, parent, dataModel) {
    // Private state
    var self = this,
        providerKey = ko.observable(data.providerKey);

    // Data
    self.loginProvider = ko.observable(data.loginProvider);

    // Other UI state
    self.removing = ko.observable(false);

    // Operations
    self.remove = function () {
        parent.errors.removeAll();
        self.removing(true);
        dataModel.removeLogin({
            loginProvider: self.loginProvider(),
            providerKey: providerKey()
        }).done(function (data) {
            self.removing(false);
            parent.logins.remove(self);
            parent.message("此登录名已删除。");
        }).failJSON(function (data) {
            var errors;

            self.removing(false);
            errors = dataModel.toErrorsArray(data);

            if (errors) {
                parent.errors(errors);
            } else {
                parent.errors.push("出现未知错误。");
            }
        });
    };
}

function SetPasswordViewModel(app, parent, dataModel) {
    var self = this;

    // Data
    self.newPassword = ko.observable("").extend({ required: true });
    self.confirmPassword = ko.observable("").extend({ required: true, equal: self.newPassword });

    // Other UI state
    self.setting = ko.observable(false);
    self.errors = ko.observableArray();
    self.validationErrors = ko.validation.group([self.newPassword, self.confirmPassword]);

    // Operations
    self.set = function () {
        self.errors.removeAll();
        if (self.validationErrors().length > 0) {
            self.validationErrors.showAllMessages();
            return;
        }
        self.setting(true);

        dataModel.setPassword({
            newPassword: self.newPassword(),
            confirmPassword: self.confirmPassword()
        }).done(function (data) {
            self.setting(false);
            parent.logins.push(new RemoveLoginViewModel({
                loginProvider: parent.localLoginProvider(),
                providerKey: parent.userName()
            }, parent, dataModel));
            parent.message("已设置你的密码。");
        }).failJSON(function (data) {
            var errors;

            self.setting(false);
            errors = dataModel.toErrorsArray(data);

            if (errors) {
                self.errors(errors);
            } else {
                self.errors.push("出现未知错误。");
            }
        });
    };
}

app.addViewModel({
    name: "Manage",
    bindingMemberName: "manage",
    factory: ManageViewModel,
    navigatorFactory: function (app) {
        return function (externalAccessToken, externalError) {
            app.errors.removeAll();
            app.view(app.Views.Manage);

            if (typeof (externalAccessToken) !== "undefined" || typeof (externalError) !== "undefined") {
                app.manage().addExternalLogin(externalAccessToken, externalError);
            } else {
                app.manage().load();
            };
        }
    }
});