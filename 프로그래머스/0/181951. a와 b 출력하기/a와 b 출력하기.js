const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})


let arr = [];

rl.on('line', function(line){
    arr = line.split(' ');
}).on('close', function(){
    console.log('a = ' + arr[0]);
    console.log('b = ' + arr[1])
})