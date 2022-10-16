import Feature from "ol/Feature";
import Polygon from "ol/geom/Polygon";
import VectorLayer from "ol/layer/Vector";
import VectorSource from "ol/source/Vector";
import Fill from "ol/style/Fill";
import Stroke from "ol/style/Stroke";
import Style from "ol/style/Style";



export function baseMap(): VectorLayer<VectorSource> {
  let mapSource = new VectorSource();
  const mapFeature = new Feature({
    geometry: new Polygon([[[0,0], [100, 0], [100, 100], [0, 100]]]),
  });
  mapSource.addFeature(mapFeature)

  let vectorLayerMap = new VectorLayer({
    source: mapSource,
    style: mapStyle
  })
  return vectorLayerMap;
}

export const mapStyle = new Style({
  stroke: new Stroke({
    color: "#66dd66",
  }),
  fill: new Fill({
    color: "#66dd66"
  })
});