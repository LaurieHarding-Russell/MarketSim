export class MarketService {

    // FIXME, will only work locally. Do I care?
    host = "localhost:8080"

    private static _instance: MarketService;

    private constructor() {
    }
  
    public static get Instance(){
        return this._instance || (this._instance = new this());
    }

    getData(): Promise<Response> {
        return fetch('market/data', {
            headers: { "Content-Type": "application/json; charset=utf-8" },
            method: 'GET'
        });
    }

    simulateYear(): Promise<Response> {
        return fetch('market/simulate-year', {
            headers: { "Content-Type": "application/json; charset=utf-8" },
            method: 'GET'
        });
    }

    reset(): Promise<Response> {
        return fetch('market/reset', {
            headers: { "Content-Type": "application/json; charset=utf-8" },
            method: 'GET'
        });
    }
}