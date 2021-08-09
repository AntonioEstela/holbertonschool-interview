#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

const start = () => {
  request(url, (error, response, body) => {
    if (error) throw error;

    charactersReq(JSON.parse(body).characters);
  });
};

const charactersReq = (characters) => {
  for (const character of characters) {
    request(character, (error, request, body) => {
      if (error) throw error;

      console.log(JSON.parse(body).name);
    });
  }
};

start();
