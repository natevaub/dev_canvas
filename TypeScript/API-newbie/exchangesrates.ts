import axios from 'axios'
import * as dotenv from 'dotenv'

// Load environment variables from .env file
dotenv.config();

// Get API key from environment variables
const apiKey = process.env.API_KEY;

console.log(apiKey);

if (!apiKey) {
	console.log('API key not found in environment variables');
	process.exit(1);
}

const RequestURL = 'https://api.freecurrencyapi.com/'


const baseCurrency = 'EUR';

const symbols = 'GBP,JPY';

const apiURL = `${RequestURL}v1/latest?apikey=${apiKey}&base_currency=${baseCurrency}&currencies=${symbols}`;

axios
  .get(apiURL)
  .then(response => {
    // Handle the API response here
    const data = response.data.data;
    console.log(data);
  })
  .catch(error => {
    // Handle errors here
    console.error(error.response.data);
  });

interface Convert {

}