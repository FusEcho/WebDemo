
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
  var obj = {data1:data1,data2:data2,data3:data3,data4:data4,data5:data5,data6:data6,data7:data7,data8:data8,data9:data9};
  var json = JSON.stringify(obj);
  mainWindow.setValues(json);

  alert("export success");
}

function slot1(object) {
    const obj = JSON.parse(object)
    document.getElementById("data1").value = obj.data1;
    document.getElementById("data2").value = obj.data2;
    document.getElementById("data3").value = obj.data3;
    document.getElementById("data4").value = obj.data4;
    document.getElementById("data5").value = obj.data5;
    document.getElementById("data6").value = obj.data6;
    document.getElementById("data7").value = obj.data7;
    document.getElementById("data8").value = obj.data8;
    document.getElementById("data9").value = obj.data9;
    alert("import success");
}
