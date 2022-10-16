import { Investor } from "./world";

export class InvestorComponent extends HTMLElement {
  host = document.createElement('investor');
  data = document.createElement('pre');

  investor: Investor = {
    name: "undefined",
    funds: 0
  };

  constructor() {
      super();

      let shadow = this.attachShadow({mode: 'open'});

      this.host.setAttribute('class','sign-in-bar');

      this.data.innerHTML = `
        TODO:
        gotta think about what to show.
      `;
      
      const style = document.createElement('style');
      style.textContent = `
      :host {
        border-style: solid 
      }
    `;
    
    this.host.appendChild(this.data);
    const linkElem = document.createElement('link');
    linkElem.setAttribute('rel', 'stylesheet');
    linkElem.setAttribute('href', 'base.css');

    this.shadowRoot!.append(style, this.host, linkElem);
  }


}