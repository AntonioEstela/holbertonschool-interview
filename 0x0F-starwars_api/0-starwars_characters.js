#!/usr/bin/node

const request = require('request');
const starWarsUrl = 'https://swapi-api.hbtn.io/api/films/';
const args = process.argv[2];

request(starWarsUrl + args, function (err, res, body) {
  if (err) {
    throw err;
  }

  const characters = JSON.parse(body).characters;

  characters.forEach(element => {
    request(element, (err, res, body) => {
      if (err) {
        console.error(err);
      }

      const name = JSON.parse(body).name;
      console.log(name);
    });
  });
});
