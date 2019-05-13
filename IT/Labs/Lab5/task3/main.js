

function disappear(x){
    document.getElementById(x).style.visibility = "hidden"; 
   
}

function display(){
    document.getElementById(1).style.visibility = "visible";
    document.getElementById(2).style.visibility = "visible";
    document.getElementById(3).style.visibility = "visible";
    document.getElementById(4).style.visibility = "visible";    
    document.getElementById('1').style.fontWeight = "normal" ;
    document.getElementById('2').style.fontWeight = "normal" ;
    document.getElementById('3').style.fontWeight = "normal" ;
    document.getElementById('4').style.fontWeight = "normal" ;
}

function bold(x)
{
    document.getElementById(x).style.fontWeight = "bold" ;
}

$('img').hide();
$('img').fadeOut();