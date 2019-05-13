var today = new Date();
var day = today.getDay();

var list = ["Sunday", "Monday", "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" ] ;

day += 5;
day %= 7;

console.log(list[day]);

