for(var i = 0; i < 18; i++) { var scriptId = 'u' + i; window[scriptId] = document.getElementById(scriptId); }

$axure.eventManager.pageLoad(
function (e) {

if (true) {

SetGlobalVariableValue('min', '0');

SetGlobalVariableValue('sec', '0');

SetGlobalVariableValue('ms', '0');

SetGlobalVariableValue('start', '0');

}

});

widgetIdToShowFunction['u8'] = function() {
var e = windowEvent;

if (((GetGlobalVariableValue('start')) == ('1')) && ((GetGlobalVariableValue('ms')) < Number('60'))) {

SetGlobalVariableValue('ms', '' + (GetNum(GetGlobalVariableValue('ms')) + 1) + '');

SetWidgetRichText('u3', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('min')) + '</span></p>');

SetWidgetRichText('u5', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('sec')) + '</span></p>');

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('ms')) + '</span></p>');

	SetPanelVisibility('u8','hidden','none',500);

}
else
if (((GetGlobalVariableValue('start')) == ('1')) && ((GetGlobalVariableValue('sec')) < Number('60'))) {

SetGlobalVariableValue('ms', '0');

SetGlobalVariableValue('sec', '' + (GetNum(GetGlobalVariableValue('sec')) + 1) + '');

SetWidgetRichText('u3', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('min')) + '</span></p>');

SetWidgetRichText('u5', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('sec')) + '</span></p>');

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('ms')) + '</span></p>');

	SetPanelVisibility('u8','hidden','none',500);

}
else
if ((GetGlobalVariableValue('start')) == ('1')) {

SetGlobalVariableValue('min', '' + (GetNum(GetGlobalVariableValue('min')) + 1) + '');

SetGlobalVariableValue('sec', '0');

SetGlobalVariableValue('ms', '0');

SetWidgetRichText('u3', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('min')) + '</span></p>');

SetWidgetRichText('u5', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('sec')) + '</span></p>');

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('ms')) + '</span></p>');

	SetPanelVisibility('u8','hidden','none',500);

}

}

widgetIdToHideFunction['u8'] = function() {
var e = windowEvent;

if (true) {
function waitufa431d2f5c6f47e6a4467ada548536c11() {

	SetPanelVisibility('u8','','none',500);
}
setTimeout(waitufa431d2f5c6f47e6a4467ada548536c11, 10);

}

}
gv_vAlignTable['u3'] = 'center';gv_vAlignTable['u13'] = 'center';document.getElementById('u12_img').tabIndex = 0;
HookClick('u12', false);

u12.style.cursor = 'pointer';
$axure.eventManager.click('u12', function(e) {

if (true) {

SetGlobalVariableValue('start', '0');

}
});
document.getElementById('u10_img').tabIndex = 0;
HookClick('u10', false);

u10.style.cursor = 'pointer';
$axure.eventManager.click('u10', function(e) {

if (true) {

SetGlobalVariableValue('start', '1');

;

	SetPanelVisibility('u8','hidden','none',500);

}
});
gv_vAlignTable['u17'] = 'center';gv_vAlignTable['u5'] = 'center';gv_vAlignTable['u1'] = 'center';document.getElementById('u14_img').tabIndex = 0;
HookClick('u14', false);

u14.style.cursor = 'pointer';
$axure.eventManager.click('u14', function(e) {

if (true) {

SetGlobalVariableValue('str', '' + (GetGlobalVariableValue('str')) + '' + (GetGlobalVariableValue('min')) + ' : ' + (GetGlobalVariableValue('sec')) + ' : ' + (GetGlobalVariableValue('ms')) + '\n');

SetWidgetFormText('u9', GetGlobalVariableValue('str'));

}
});
gv_vAlignTable['u15'] = 'center';document.getElementById('u16_img').tabIndex = 0;
HookClick('u16', false);

u16.style.cursor = 'pointer';
$axure.eventManager.click('u16', function(e) {

if (true) {

SetGlobalVariableValue('sec', '0');

SetGlobalVariableValue('min', '0');

SetGlobalVariableValue('ms', '0');

SetGlobalVariableValue('start', '0');

SetGlobalVariableValue('str', '');

SetWidgetRichText('u3', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('min')) + '</span></p>');

SetWidgetRichText('u5', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('sec')) + '</span></p>');

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:Arial;font-size:13px;font-weight:normal;font-style:normal;text-decoration:none;color:#333333;">' + (GetGlobalVariableValue('ms')) + '</span></p>');

SetWidgetFormText('u9', '' + (GetGlobalVariableValue('str')) + '');

}
});
HookHover('u2', false);
gv_vAlignTable['u11'] = 'center';gv_vAlignTable['u7'] = 'center';