const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})


let input = [];

rl.on('line', (line)=>{
    input = line.split(' ');
    
    console.log("a = " + input[0]);
    console.log("b = " + input[1]);
    rl.close();
})

