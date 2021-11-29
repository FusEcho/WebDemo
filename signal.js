
$(document).ready(function() {
  try {
    mainWindow.sendstr.connect(slot1);
  }
  catch(e) {
    alert(e);
  }
});
 
function slot2() {

  var data1 = document.getElementById("data1").value;
  var data2 = document.getElementById("data2").value;
  var data3 = document.getElementById("data3").value;
  var data4 = document.getElementById("data4").value;
  var data5 = document.getElementById("data5").value;
  var data6 = document.getElementById("data6").value;
  var data7 = document.getElementById("data7").value;
  var data8 = document.getElementById("data8").value;
  var data9 = document.getElementById("data9").value;

  mainWindow.setValues(data1, data2, data3, data4, data5, data6, data7, data8, data9);

  alert("export success");
}

function slot1(object) {
    document.getElementById("data1").value = object.data1;
    document.getElementById("data2").value = object.data2;
    document.getElementById("data3").value = object.data3;
    document.getElementById("data4").value = object.data4;
    document.getElementById("data5").value = object.data5;
    document.getElementById("data6").value = object.data6;
    document.getElementById("data7").value = object.data7;
    document.getElementById("data8").value = object.data8;
    document.getElementById("data9").value = object.data9;
    alert("import success");
}
