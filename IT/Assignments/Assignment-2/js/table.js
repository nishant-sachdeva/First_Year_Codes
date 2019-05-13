$(document).ready(function()
{
    $("cars").change(function()
    {
        var n = $('#cars').text();
        $("carsss").val() = n;
    });
    $(".add-row").click(function()
    {
        var name = $("#name").val();
        var skill = $("#skill").val();
        var level = $("#level").val();
        var markup = "<tr><td colspan=" + "\"2\"" + ">" + name + "</td><td>" + skill+ "</td><td>" +  level + "</td></tr>" ;
        $("table tbody").append(markup);
    });
});    