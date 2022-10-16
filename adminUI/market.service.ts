import { World } from "./world";

export class MarketService {

    // FIXME, will only work locally. Do I care?
    world: World = {
        companies: [],
        people: [],
        investors: [],
        year: -1
    };

    private static _instance: MarketService;

    private constructor() {
    }
  
    public static get Instance(){
        return this._instance || (this._instance = new this());
    }

    async getData(): Promise<World> {
        this.world = JSON.parse(await (
            await (
                fetch('market/data', {
                    headers: { "Content-Type": "application/json; charset=utf-8" },
                    method: 'GET'
                })
            )
        ).text());
        return this.viewData();
    }

    async simulateYear(): Promise<World> {
        this.world = JSON.parse(await (
            await (
                fetch('market/simulate-year', {
                    headers: { "Content-Type": "application/json; charset=utf-8" },
                    method: 'GET'
                })
            )
        ).text());
        return this.viewData();
    }

    async reset(): Promise<World> {
        this.world = JSON.parse(await (
            await (
                fetch('market/reset', {
                    headers: { "Content-Type": "application/json; charset=utf-8" },
                    method: 'GET'
                })
            )
        ).text());
        return this.viewData();
    }

    viewData() {
        return JSON.parse(JSON.stringify(this.world));
    }
}