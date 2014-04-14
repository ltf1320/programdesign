for(var i = 0; i < 100; i++) { var scriptId = 'u' + i; window[scriptId] = document.getElementById(scriptId); }

$axure.eventManager.pageLoad(
function (e) {

if (true) {

	SetPanelVisibility('u86','hidden','none',500);

SetGlobalVariableValue('RandomVariable', '235245265235624523654252623535362644253652365242352642524642523456252425632654523654235622352452652356245236542526235353626442536523652423526425246425234562524256326545236542356223524526523562452365425262353536264425365236524235264252464252345625242563265452365423562');

SetGlobalVariableValue('currentRandomVariable', '0');

	SetPanelState('u3', 'pd0u3','none','',500,'none','',500);

}

});

widgetIdToShowFunction['u99'] = function() {
var e = windowEvent;

if ((GetWidgetText('u90')) < Number('60')) {

SetWidgetRichText('u9', '<p style="text-align:center;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">你的反应能力太太一般了!</span></p>');

}

if (((GetWidgetText('u90')) >= Number('60')) && ((GetWidgetText('u90')) < Number('100'))) {

SetWidgetRichText('u9', '<p style="text-align:center;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">可见你不是一般的人!</span></p>');

}

}

widgetIdToHideFunction['u99'] = function() {
var e = windowEvent;

if (true) {

}

}

widgetIdToShowFunction['u94'] = function() {
var e = windowEvent;

if ((GetWidgetText('u93')) > Number('0')) {
function waitu15d76f9e63a04c16b6f220002141d64f1() {

SetWidgetRichText('u93', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">' + (GetWidgetText('u93') - 1) + '</span></p>');

	SetPanelVisibility('u94','hidden','none',500);
}
setTimeout(waitu15d76f9e63a04c16b6f220002141d64f1, 1000);

}

if ((GetWidgetText('u93')) == ('0')) {

	MoveWidgetBy('u86', GetNum('0'), GetNum('-70'),'none',500);

	SetPanelVisibility('u99','hidden','none',500);

	SetPanelState('u3', 'pd7u3','none','',500,'none','',500);

}

}

widgetIdToHideFunction['u94'] = function() {
var e = windowEvent;

if (true) {

	SetPanelVisibility('u94','toggle','none',500);

}

}

widgetIdToShowFunction['u2'] = function() {
var e = windowEvent;

if (true) {
function waitufb04388f44f242f6a9ccd20850d8e9061() {

SetGlobalVariableValue('currentRandomVariable', '' + (GetNum(GetGlobalVariableValue('currentRandomVariable')) + 1) + '');

	SetPanelStateByValue('u3', '' + (GetGlobalVariableValue('RandomVariable').substring(GetGlobalVariableValue('currentRandomVariable'), GetNum(GetGlobalVariableValue('currentRandomVariable')) + 1)) + '','none','',500,'none','',500);

SetWidgetRichText('u90', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">' + (GetNum(GetWidgetText('u90')) + 1) + '</span></p>');
}
setTimeout(waitufb04388f44f242f6a9ccd20850d8e9061, 100);

}

}

widgetIdToHideFunction['u2'] = function() {
var e = windowEvent;

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}

}
gv_vAlignTable['u21'] = 'center';gv_vAlignTable['u11'] = 'center';gv_vAlignTable['u76'] = 'center';gv_vAlignTable['u17'] = 'center';gv_vAlignTable['u93'] = 'top';gv_vAlignTable['u8'] = 'center';gv_vAlignTable['u32'] = 'center';gv_vAlignTable['u1'] = 'center';gv_vAlignTable['u97'] = 'center';gv_vAlignTable['u67'] = 'center';gv_vAlignTable['u30'] = 'center';gv_vAlignTable['u60'] = 'center';gv_vAlignTable['u89'] = 'top';gv_vAlignTable['u34'] = 'center';gv_vAlignTable['u19'] = 'center';document.getElementById('u7_img').tabIndex = 0;
HookHover('u7', false);

u7.style.cursor = 'pointer';
$axure.eventManager.click('u7', function(e) {

if (true) {

	SetPanelState('u3', 'pd1u3','none','',500,'none','',500);

	SetPanelVisibility('u86','','fade',100);

	MoveWidgetBy('u86', GetNum('0'), GetNum('70'),'linear',100);

SetWidgetRichText('u93', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">60</span></p>');

	SetPanelVisibility('u94','hidden','none',500);

SetWidgetRichText('u90', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">0</span></p>');

}
});
document.getElementById('u79_img').tabIndex = 0;
HookHover('u79', false);

u79.style.cursor = 'pointer';
$axure.eventManager.click('u79', function(e) {

if (true) {

	parent.window.close();

}
});
document.getElementById('u81_img').tabIndex = 0;
HookHover('u81', false);

u81.style.cursor = 'pointer';
$axure.eventManager.click('u81', function(e) {

if (true) {

	NewTab('http://www.yl-blog.com', "");

}
});
gv_vAlignTable['u85'] = 'top';gv_vAlignTable['u41'] = 'center';gv_vAlignTable['u71'] = 'center';gv_vAlignTable['u15'] = 'center';gv_vAlignTable['u45'] = 'center';gv_vAlignTable['u92'] = 'top';document.getElementById('u83_img').tabIndex = 0;
HookHover('u83', false);

u83.style.cursor = 'pointer';
$axure.eventManager.click('u83', function(e) {

if (true) {

	SetPanelState('u3', 'pd6u3','none','',500,'none','',500);

}
});
u22.tabIndex = 0;

u22.style.cursor = 'pointer';
$axure.eventManager.click('u22', function(e) {

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}
});
gv_vAlignTable['u13'] = 'center';gv_vAlignTable['u52'] = 'center';gv_vAlignTable['u43'] = 'center';gv_vAlignTable['u73'] = 'center';gv_vAlignTable['u58'] = 'center';gv_vAlignTable['u6'] = 'center';document.getElementById('u77_img').tabIndex = 0;
HookHover('u77', false);

u77.style.cursor = 'pointer';
$axure.eventManager.click('u77', function(e) {

if (true) {

	SetPanelState('u3', 'pd1u3','none','',500,'none','',500);

	SetPanelVisibility('u86','','fade',100);

	MoveWidgetBy('u86', GetNum('0'), GetNum('70'),'linear',100);

SetWidgetRichText('u93', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">60</span></p>');

SetWidgetRichText('u90', '<p style="text-align:left;"><span style="font-family:Arial;font-size:20px;font-weight:bold;font-style:normal;text-decoration:none;color:#FFFFFF;">0</span></p>');

	SetPanelVisibility('u94','hidden','none',500);

}
});
gv_vAlignTable['u90'] = 'top';gv_vAlignTable['u50'] = 'center';gv_vAlignTable['u98'] = 'top';gv_vAlignTable['u24'] = 'center';gv_vAlignTable['u54'] = 'center';gv_vAlignTable['u28'] = 'center';gv_vAlignTable['u39'] = 'center';gv_vAlignTable['u69'] = 'center';u61.tabIndex = 0;

u61.style.cursor = 'pointer';
$axure.eventManager.click('u61', function(e) {

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}
});
u35.tabIndex = 0;

u35.style.cursor = 'pointer';
$axure.eventManager.click('u35', function(e) {

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}
});
gv_vAlignTable['u26'] = 'center';gv_vAlignTable['u65'] = 'center';gv_vAlignTable['u56'] = 'center';document.getElementById('u5_img').tabIndex = 0;
HookHover('u5', false);

u5.style.cursor = 'pointer';
$axure.eventManager.click('u5', function(e) {

if (true) {

	SetPanelState('u3', 'pd0u3','none','',500,'none','',500);

}
});
gv_vAlignTable['u82'] = 'center';gv_vAlignTable['u9'] = 'top';gv_vAlignTable['u63'] = 'center';u48.tabIndex = 0;

u48.style.cursor = 'pointer';
$axure.eventManager.click('u48', function(e) {

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}
});
gv_vAlignTable['u88'] = 'center';gv_vAlignTable['u78'] = 'center';gv_vAlignTable['u47'] = 'center';gv_vAlignTable['u80'] = 'center';gv_vAlignTable['u84'] = 'center';gv_vAlignTable['u37'] = 'center';u74.tabIndex = 0;

u74.style.cursor = 'pointer';
$axure.eventManager.click('u74', function(e) {

if (true) {

	SetPanelVisibility('u2','toggle','none',500);

}
});
gv_vAlignTable['u4'] = 'top';gv_vAlignTable['u91'] = 'top';