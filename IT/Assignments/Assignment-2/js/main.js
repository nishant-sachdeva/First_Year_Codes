var myVar;

function myFunction() {
  myVar = setTimeout(showPage, 2000);
}

function showPage() {
  document.getElementById("container").style.display = "none";
  document.getElementById("myDiv").style.display = "block";
}

// this so far loads the loader and loads the page with animation

window.onscroll = function() {change()};

var navbar = document.getElementById("navbar");
var sticky = navbar.offsetTop;

navbar.classList.add("a:hover");

function change() {
  if (window.pageYOffset >= sticky) {
    navbar.classList.add("sticky")
  } else {
    navbar.classList.remove("sticky");
  }
}


//this second one is for a sticky navbar
// now we will deal with the counter

function clickCounter() {
  if (typeof(Storage) !== "undefined") {
    if (localStorage.clickcount) {
      localStorage.clickcount = Number(localStorage.clickcount)+1;
    } else {
      localStorage.clickcount = 1;
    }
    document.getElementById("result").innerHTML = "Net Likes :  " + localStorage.clickcount;
  } else {
    document.getElementById("result").innerHTML = "Sorry, your browser does not support web storage...";
  }
}

function clickDownCounter() {
  if (typeof(Storage) !== "undefined") {
    if (localStorage.clickcount) {
      localStorage.clickcount = Number(localStorage.clickcount)-1;
    } else {
      localStorage.clickcount = 1;
    }
    document.getElementById("result").innerHTML = "Net Likes :  " + localStorage.clickcount;
  } else {
    document.getElementById("result").innerHTML = "Sorry, your browser does not support web storage...";
  }
}

// THE next section deals with the rotating images;
// ../images/dinner , dogs, mall, star, sunset;

function circulate(element){
  var x = document.getElementById('rotate');
  var y = x.getAttribute("src");
  if(y == "../images/dinner.jpeg")
    y = "../images/dogs.jpeg";
  else if(y == "../images/dogs.jpeg")
    y = "../images/mall.jpeg";
  else if(y == "../images/mall.jpeg")
    y = "../images/star.jpeg";
  else if(y == "../images/star.jpeg")
    y = "../images/sunset.jpeg";
  else if(y == "../images/sunset.jpeg")
    y = "../images/dinner.jpeg";

  x.setAttribute("src", y);
}