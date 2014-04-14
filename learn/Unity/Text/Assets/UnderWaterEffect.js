private var defaultFog = RenderSettings.fog;
private var defaultFogColor = RenderSettings.fogColor;
private var defaultFogDensity = RenderSettings.fogDensity;
private var defaultSkybox = RenderSettings.skybox;
var noSkybox : Material;
function OnTriggerStay (hit : Collider)
{
if(hit.gameObject.tag=="WaterColler"){
RenderSettings.fog = true;
RenderSettings.fogColor = Color (0, 0.4, 0.7, 0.6);
RenderSettings.fogDensity = 0.04;
RenderSettings.skybox = noSkybox;
}
}
function OnTriggerExit (hit : Collider) {
if(hit.gameObject.tag=="WaterColler"){
RenderSettings.fog = defaultFog;
RenderSettings.fogColor = defaultFogColor;
RenderSettings.fogDensity = defaultFogDensity;
RenderSettings.skybox = defaultSkybox;
}
}