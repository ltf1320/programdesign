for(var i = 0; i < 20; i++) { var scriptId = 'u' + i; window[scriptId] = document.getElementById(scriptId); }

$axure.eventManager.pageLoad(
function (e) {

if (true) {

	SetPanelVisibility('u9','hidden','none',500);

}

});

widgetIdToShowFunction['u9'] = function() {
var e = windowEvent;

if (((GetWidgetText('u8')) >= Number('0')) && (((GetWidgetText('u7')) >= Number('0')) && ((GetWidgetText('u6')) > Number('0')))) {

SetWidgetRichText('u6', '<p style="text-align:center;"><span style="font-family:华文新魏;font-size:48px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">' + (GetWidgetText('u6') - 1) + '</span></p>');

	SetPanelVisibility('u9','hidden','none',500);

}
else
if (((GetWidgetText('u8')) >= Number('0')) && (((GetWidgetText('u7')) > Number('0')) && ((GetWidgetText('u6')) == ('0')))) {

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:华文新魏;font-size:48px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">' + (GetWidgetText('u7') - 1) + '</span></p>');

SetWidgetRichText('u6', '<p style="text-align:center;"><span style="font-family:华文新魏;font-size:48px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">60</span></p>');

	SetPanelVisibility('u9','hidden','none',500);

}
else
if (((GetWidgetText('u8')) > Number('0')) && (((GetWidgetText('u7')) == ('0')) && ((GetWidgetText('u6')) == ('0')))) {

SetWidgetRichText('u8', '<p style="text-align:center;"><span style="font-family:华文新魏;font-size:48px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">' + (GetWidgetText('u8') - 1) + '</span></p>');

SetWidgetRichText('u7', '<p style="text-align:center;"><span style="font-family:华文新魏;font-size:48px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">60</span></p>');

	SetPanelVisibility('u9','hidden','none',500);

}

}

widgetIdToHideFunction['u9'] = function() {
var e = windowEvent;

if (true) {
function waituac872a39aa514f4e9a1218bec4d309711() {

	SetPanelVisibility('u9','toggle','none',500);
}
setTimeout(waituac872a39aa514f4e9a1218bec4d309711, 1000);

}

}
gv_vAlignTable['u3'] = 'center';gv_vAlignTable['u12'] = 'center';gv_vAlignTable['u8'] = 'top';gv_vAlignTable['u19'] = 'center';gv_vAlignTable['u17'] = 'center';gv_vAlignTable['u5'] = 'center';gv_vAlignTable['u1'] = 'center';gv_vAlignTable['u14'] = 'center';gv_vAlignTable['u6'] = 'top';gv_vAlignTable['u7'] = 'top';