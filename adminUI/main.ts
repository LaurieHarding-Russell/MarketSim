import Map from 'ol/Map';
import View from 'ol/View';
import VectorLayer from 'ol/layer/Vector';

import {World} from "./world";
import { MarketService } from './market.service';
import VectorSource from 'ol/source/Vector';
import Feature from 'ol/Feature';
import { Point, Polygon } from 'ol/geom';
import { InvestorComponent } from './investor.component';
import { BusinessComponent } from './business.component';
import { baseMap } from './map.util';

customElements.define('investor-component', InvestorComponent);
customElements.define('business-component', BusinessComponent);

let peopleSource = new VectorSource();


let vectorLayerPeople = new VectorLayer({
    source: peopleSource
})

const investorData: HTMLCanvasElement = <HTMLCanvasElement>document.querySelector("#investor")  
const businessData: HTMLCanvasElement = <HTMLCanvasElement>document.querySelector("#business")  

updateData(peopleSource);

let marketService = MarketService.Instance;

// FIXME, webcomponent maybe?
let refreshButton = document.querySelector("#refresh");
if (!refreshButton) throw "oh no hacky 1!";
refreshButton.addEventListener("click", async() => {
  let world: World = await marketService.getData();
  updateVisibleData(world, peopleSource)
});

let simulateButton = document.querySelector("#simulate");
if (!simulateButton) throw "oh no! hacky 2!";
simulateButton.addEventListener("click", async() => {
    let world: World = await marketService.simulateYear();
    updateVisibleData(world, peopleSource)
});

let resetButton = document.querySelector("#reset");
if (!resetButton) throw "oh no! hacky 3!";
resetButton.addEventListener("click", async() => {
    let world: World = await marketService.reset();
    updateVisibleData(world, peopleSource)
});

let map = new Map({
  target: 'map',
  layers: [
    baseMap(),
    vectorLayerPeople
  ],
  view: new View({
    center: [50, 50], // fixme maybe get from server incase we increase the size
    zoom: 18
  })
});

async function updateData(peopleSource: VectorSource) {
    let marketService = MarketService.Instance;
    let world: World = await marketService.getData();
    updateVisibleData(world, peopleSource)
}

function updateVisibleData(world: World, peopleSource: VectorSource) {
    world.people.forEach(person => {
        const personFeature = new Feature({
            geometry: new Point([person.coordinate.y, person.coordinate.x])
          });
        peopleSource.addFeature(personFeature)
    })

    investorData.innerHTML = "";
    world.investors.forEach(investor => {
      const investorNode: InvestorComponent = document.createElement("investor-component") as InvestorComponent;
      investorNode.investor = investor;
      investorData.appendChild(investorNode);
    })

    // businessData
    businessData.innerHTML = "";
    world.companies.forEach(company => {
      const companyNode: BusinessComponent = document.createElement("business-component") as BusinessComponent;
      console.log(company, companyNode);
      companyNode.company = company;
      businessData.appendChild(companyNode);
    })
} 