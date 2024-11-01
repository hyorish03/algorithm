// const readline = require('readline');
// const rl = readline.createInterface({
//     input: process.stdin,
//     output: process.stdout
// });


// rl.on('line', function (line) {
//     input = [line];
// }).on('close',function(){
//     str = input[0];
// });

// for(const i in input){
//     if(i === i.toUpperCase())
//         output+= i.toUpperCase()
//     else
//         outPut+= i.toLowerCase()
// }

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


let input = [];
let str = "";
rl.on('line', function(line){
    input = [line];
}).on('close', AnswerFn)


function AnswerFn(){
    str=input[0];


let answer = "";
for(let i = 0; i < str.length; i++){
    if('A' <= str[i] && str[i] <= 'Z'){
        answer += str[i].toLowerCase();
    } else {
        answer += str[i].toUpperCase();
    }
}
console.log(answer);

}