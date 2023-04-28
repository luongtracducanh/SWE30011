$(document).ready(function () {
  $.ajax({
    url: "http://localhost/SWE30011-Assignment2/php/data.php",
    type: "GET",
    success: function (data) {
      let numOfStatement = 7;
      for (let i = 0; i < numOfStatement; i++) {
        console.log(data[i])
      }

      let elements = ["maxTemp", "minTemp", "maxHumid", "minHumid", "avgTemp", "avgHumid"]
      for (let i = 0; i < numOfStatement - 1; i++) {
        document.getElementById(elements[i]).innerHTML = data[i + 1][elements[i]];
      }

      var id = [];
      var temp = [];
      var humid = [];

      for (var i in data[0]) {
        id.push(data[0][i].ID);
        temp.push(data[0][i].Temperature);
        humid.push(data[0][i].Humidity);
      }

      var chartdata = {
        labels: id,
        datasets: [
          {
            label: "Temperature (C)",
            fill: false,
            lineTension: 0.1,
            backgroundColor: "rgba(59, 89, 152, 0.75)",
            borderColor: "rgba(59, 89, 152, 1)",
            pointHoverBackgroundColor: "rgba(59, 89, 152, 1)",
            pointHoverBorderColor: "rgba(59, 89, 152, 1)",
            data: temp
          },
          {
            label: "Humidity (%)",
            fill: false,
            lineTension: 0.1,
            backgroundColor: "rgba(29, 202, 255, 0.75)",
            borderColor: "rgba(29, 202, 255, 1)",
            pointHoverBackgroundColor: "rgba(29, 202, 255, 1)",
            pointHoverBorderColor: "rgba(29, 202, 255, 1)",
            data: humid
          },
        ]
      };

      var ctx = $("#mycanvas");

      var LineGraph = new Chart(ctx, {
        type: 'line',
        data: chartdata,
        options: {
          scales: {
            yAxes: [{
              display: true,
              ticks: {
                suggestedMax: 100,
                suggestedMin: 0,    // minimum will be 0, unless there is a lower value.
                // OR //
                beginAtZero: true   // minimum value will be 0.
              }
            }]
          }
        }
      });
    },
    error: function (data) {
      console.log("error");
    }
  });
});