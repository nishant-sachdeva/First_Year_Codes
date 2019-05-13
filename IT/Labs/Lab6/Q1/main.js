function build(){
    $.ajax({
        url: 'khana.json',
        type: 'get',
        dataType : 'json',
        success: function(data) {
            namesArray = data;
            for(var i in namesArray){
                $("#select1").append("<option>" + namesArray[i].cuisine + "</option>");
            } // bob
        }
    });
}


$("#select1").click(function(){
    $.ajax({url: "http://localhost:8000/khana.json", success: function(result){
        $("#div1").html(result);
    }});
});  