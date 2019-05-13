//function to check answer of experiment.
function checkCondition(b)
{
   var count = 49;
   var your_ans = [];
   var cor_ans = [];
   cor_ans = b.split(',');
   var all=1;
   var i;

   for(i=0;i<count;i++)				//to store your answer
   {
      //Gets value of the users answer.
      your_ans[i]=document.getElementById(i).value;
   }
   for (i=0;i<count;i++)
   {
      //Compares the User's answer with the Correct Answer
      if(parseFloat(your_ans[i]) === parseFloat(cor_ans[i]))
      {
          //If it is correct all the cells turn green
         document.getElementById("td"+i).innerHTML="<input type= \"text\" size= \"3\" name=\""+i+"\"id=\""+i+"\" style=\"background-color:green;\" value=\""+your_ans[i]+"\"/>";
      }
      else
      {
           // If it is wrong all the cells turn red
         document.getElementById("td"+i).innerHTML="<input type= \"text\" size= \"3\" name=\""+i+"\"id=\""+i+"\" style=\"background-color:red;\" value=\""+your_ans[i]+"\"/>";
         all=0;

      }
   }

   if(all==1)
   {
        //If it is correct, Right Answer is displayed.
      document.getElementById('right_ans').innerHTML="<h2 style=\"color:green;\">Right Answer</h2>";
   }
   else
     //If it is wrong, Wrong Answer is displayed.
   document.getElementById('result').innerHTML="<h2 style=\"color:red;\">Wrong Answer</h2>";
}
