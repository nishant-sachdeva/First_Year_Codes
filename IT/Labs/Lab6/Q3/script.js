function showCustomer(str) {
    var xhttp;    
    if (str == "") {
      document.getElementById("txtHint").innerHTML = "";
      return;
    }
    xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        console.log(this.responseText);
      }
    };
    xhttp.open("GET", "http://localhost:8000/khana.json"+str, true);
    xhttp.send();
}

showCustomer("Cheesecake Factory")