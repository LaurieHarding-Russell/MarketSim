import { Investor } from "./world";

export class InvestorComponent extends HTMLElement {
  host = document.createElement('investor');
  data = document.createElement('div');
  name = document.createElement('h3');
  funds = document.createElement('span');
  
  public set investor(investor: Investor) {
    this.name.innerText = investor.name;
    this.funds.innerText = `Funds: ${investor.funds}`;
  }

  constructor() {
      super();

      let shadow = this.attachShadow({mode: 'open'});

      this.host.setAttribute('class','investor');
      this.data.appendChild(this.funds);

      const style = document.createElement('style');
        style.textContent = `
        investor {
          display:block;
          border-top: 2px solid yellow;
        }
      `;
      
      this.host.appendChild(this.name);
      this.host.appendChild(this.data);
    
    this.host.appendChild(this.data);
    const linkElem = document.createElement('link');
    linkElem.setAttribute('rel', 'stylesheet');
    linkElem.setAttribute('href', 'base.css');

    this.shadowRoot!.append(style, this.host, linkElem);
  }


}