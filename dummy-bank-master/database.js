const Sequelize = require('sequelize');

const connectionUrl = 'postgres://localhost:5432/morgan';
const database = new Sequelize(connectionUrl);

module.exports = database;
