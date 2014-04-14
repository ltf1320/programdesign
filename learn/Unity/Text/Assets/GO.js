var AddSpeed=5;
//定义一个变换对象cubeGO
var cubeGO:Transform;
function Update () {
//在逐帧播放的过程当中，一旦按下G键cubeGO就以AddSpeed速度，朝Z轴方向运动
if(Input.GetKey(KeyCode.G)){
cubeGO.Translate(AddSpeed,0,0);
}
}