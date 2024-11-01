const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inp = [];

rl.on('line', function(line){
    inp = line.split(" ");
}).on('close', function(){
    let str = "";
    for(let i = 0; i < inp[1]; i++){
        str += inp[0];
    }
    console.log(str);
})