import { Company } from "./world";

export class BusinessComponent extends HTMLElement {
  host = document.createElement('business');
  data = document.createElement('div');
  name = document.createElement('h3');
  funds = document.createElement('span');

  public set company(company: Company) {
    console.log(company);
    this.name.innerText = company.name;
    this.funds.innerText = `Funds: ${company.funds}`;
  }

  constructor() {
      super();

      let shadow = this.attachShadow({mode: 'open'});

      this.host.setAttribute('class','business');
      this.data.appendChild(this.funds);

      const style = document.createElement('style');
        style.textContent = `
        business {
          display:block;
          border-top: solid;
        }
      `;
      
      this.host.appendChild(this.name);
      this.host.appendChild(this.data);
      const linkElem = document.createElement('link');
      linkElem.setAttribute('rel', 'stylesheet');
      linkElem.setAttribute('href', 'base.css');

      this.shadowRoot!.append(style, this.host, linkElem);
  }


}