const apikey="b86e0f2d7bb5e996d5e6c819b80ee908"
const apiurl="https://api.openweathermap.org/data/2.5/weather?&units=metric&q="
const searchbox=document.querySelector(".search input")
const searchbtm=document.querySelector(".search button")
const weatherIcon=document.querySelector(".weather img")
//checkWeather("taipei");//這是預設
async function checkWeather(cityname){ //async是異步操作的函式，讓有await的程式碼可以進行異步操作，就是一個延遲可以確保資料有解析完
    const reaponse=await fetch(apiurl + cityname + `&appid=${apikey}`); //fetch是向一個網址發送請求的方法，${}就像python的f字串，記得用他媽的反引號
    var data= await reaponse.json() //轉換成json格式
    console.log(data)
    if(reaponse.status==404){
        document.querySelector(".error").style.display= 'block';
        document.querySelector(".weather").style.display= 'none';
    }
    else{
        document.querySelector(".city").innerHTML=data.name
        document.querySelector(".temperature").innerHTML=(Math.round(data.main.temp)+'℃')
        document.querySelector(".humitext").innerHTML=(data.main.humidity+'%')
        document.querySelector(".windtext").innerHTML=(data.wind.speed+' Km/h')

        document.querySelector(".weather").style.display= 'block';
        document.querySelector(".error").style.display= 'none';
        //document.querySelector(".detail").style.display= 'block';
    
        if(data.weather[0].main=="clear"){
            weatherIcon.src="IMG\\clear.png";
        }
        else if(data.weather[0].main=="Clouds"){
            weatherIcon.src="IMG\\clouds.png";
        }
        else if(data.weather[0].main=="Drizzle"){
            weatherIcon.src="IMG\\drizzle.png";
        }
        else if(data.weather[0].main=="Rain"){
            weatherIcon.src="IMG\\rain.png"
        }
        else if(data.weather[0].main=="Snow"){
            weatherIcon.src="IMG\\snow.png"
        }
        else if(data.weather[0].main=="Mist"){
            weatherIcon.src="IMG\\mist.png"
        }
    }
}
searchbtm.addEventListener('click',()=>{
    checkWeather(searchbox.value)
})
