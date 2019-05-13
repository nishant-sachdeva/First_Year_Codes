var string = "  hello world to you too sir  "
var s = string.trim();
var arr = new Array
arr = [...s];

for (var i = 0 ; i<arr.length ; i++){
  if(arr[i] == ' '){
    arr[i] = arr[i+1];
    arr[i+1] = ' ';i++;
  }
}

s = arr.join();
console.log(s);


