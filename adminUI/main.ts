import Map from 'ol/Map';
import View from 'ol/View';
import VectorLayer from 'ol/layer/Vector';

import {World} from "./world";
import { MarketService } from './market.service';
import VectorSource from 'ol/source/Vector';
import Feature from 'ol/Feature';
import { Point } from 'ol/geom';

let peopleSource = new VectorSource();

let vectorLayerPeople = new VectorLayer({
    source: peopleSource
})

const dataPre: HTMLCanvasElement | null = document.querySelector("#data")    

updateData(peopleSource);


// FIXME, webcomponent maybe?
let refreshButton = document.querySelector("#refresh");
if (!refreshButton) throw "oh no hacky 1!";
refreshButton.addEventListener("click", () => {
    updateData(peopleSource);
});

let simulateButton = document.querySelector("#simulate");

if (!simulateButton) throw "oh no! hacky 2!";
simulateButton.addEventListener("click", async() => {
    let marketService = MarketService.Instance;
    let world: World = JSON.parse(await (await marketService.simulateYear()).text());
    updateMapData(world, peopleSource)
});

let map = new Map({
  target: 'map',
  layers: [
    vectorLayerPeople
  ],
  view: new View({
    center: [0, 0],
    zoom: 2
  })
});


async function updateData(peopleSource: VectorSource) {
    console.log("test!!!");
    let marketService = MarketService.Instance;
    let world: World = JSON.parse(await (await marketService.getData()).text());
    updateMapData(world, peopleSource)
}

function updateMapData(world: World, peopleSource: VectorSource) {
    world.people.forEach(person => {
        const personFeature = new Feature({
            geometry: new Point([person.coordinate.y, person.coordinate.x])
          });
        peopleSource.addFeature(personFeature)
    })
}