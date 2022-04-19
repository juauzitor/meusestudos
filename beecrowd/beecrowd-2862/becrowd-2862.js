const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

var n = 0;
var p = 0;
console.log(n)
function addn() {
    readline.question('', num =>{
        n += num;
        readline.close();
    });
}

function addp() {
    readline.question('', num =>{
        p = num;
        readline.close();
    });
}

addn();

for (let index = 0; index < n; index++) {
    addp();
    if (p > 8000) {
        console.log("Mais de 8000!")
    } else {
        console.log("Inseto!")
    }
}

