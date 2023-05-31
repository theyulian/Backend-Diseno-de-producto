const mongoose = require('mongoose');
const bcrypt = require('bcrypt');

var dispositivos=new mongoose.Schema({
    Temp:String,
    Tiempo:String
});

module.exports=mongoose.model('Variables',dispositivos); 