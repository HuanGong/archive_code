var express = require('express');
var app = new express();
var server = app.listen(3000);
//var server = require('http').Server(app);
var io = require('socket.io').listen(server)

var Loger = require('log'),
    log = new Loger('debug');

var port = process.env.PORT || 3000;

app.get('/', function(req, res){
   res.redirect("index.html"); 
});

app.get('/user', function(req, res, next){
    //print("get a /user request")
    console.log(req, res)
    res.jsonp({status: "gonghuan"});
    //res.json({"name":"gonghuan"})
    //res.end();
})

app.get('/jsonp',function(req,res,next){  //返回jsonp  
   res.jsonp({status:'jsonp'});  
});
  
app.get('/json',function(req,res,next){   //返回json  
    res.jsonp({status:'json'});  
});

app.use(express.static(__dirname + "/public"));

io.set('log level', 0);

io.on('connection', function(socket){
    log.info('##########socket io connection')
    socket.on('stream', function(image){
        socket.broadcast.emit('stream', image);
    });
});

