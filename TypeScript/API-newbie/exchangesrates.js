"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var axios_1 = require("axios");
var dotenv = require("dotenv");
// Load environment variables from .env file
dotenv.config();
// Get API key from environment variables
var apiKey = process.env.API_KEY;
console.log(apiKey);
if (!apiKey) {
    console.log('API key not found in environment variables');
    process.exit(1);
}
var RequestURL = 'https://api.freecurrencyapi.com/';
var baseCurrency = 'EUR';
var symbols = 'GBP,JPY';
var apiURL = "".concat(RequestURL, "v1/latest?apikey=").concat(apiKey, "&base_currency=").concat(baseCurrency, "&currencies=").concat(symbols);
axios_1.default
    .get(apiURL)
    .then(function (response) {
    // Handle the API response here
    var data = response.data.data;
    console.log(data);
})
    .catch(function (error) {
    // Handle errors here
    console.error(error.response.data);
});
