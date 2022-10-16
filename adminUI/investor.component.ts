
export class InvestorComponent extends HTMLElement {
  host = document.createElement('investor');
  data = document.createElement('pre');

  constructor() {
      super();

      let shadow = this.attachShadow({mode: 'open'});

      this.host.setAttribute('class','sign-in-bar');

      this.data.innerHTML = `
        TODO:
        gotta think about what to show.
      `
      
      this.host.appendChild(this.data);
  }


}