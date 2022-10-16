export interface World {
  companies: Array<Company>;
  people: Array<Person>;
  investors: Array<Investor>;
  year: number;
}

export interface Company {
  name: string;
  funds: number;
}

export interface Coordinate {
  x: number;
  y: number;
}

export interface Person {
  coordinate: Coordinate;
  funds: number;
}

export interface Investor {
  name: string;
  funds: number;
}