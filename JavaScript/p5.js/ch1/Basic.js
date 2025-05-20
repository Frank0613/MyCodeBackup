function setup() { //開始的時候執行一次，像unity的Start
  createCanvas(400, 400);
  console.log("Hellow World")

  car=new Mycar("Car","Toyota",2020)  //這裡就是constructor裡的東西，一創建就會帶有，就不用像accelerate一樣要再寫一行
  car.accelerate(10)
  car.accelerate(90)
  car.echo()

  jeep=new MyJeep("Jeep","賓士",2021,"有")
  jeep.accelerate(30)
  jeep.echo()


}

function draw() { //一直跑，像unity的Update:60hz
  background(220);
  circle(150,300,100) //在200,200的位置新增直徑100的圓
  circle(250,300,100)
  rect(150,20,100,300)
  
}

class Mycar{
  
  constructor(_name,_brand,_year){  //這裡包含這個Class的基本資料
    this.name=_name //前面加this代表是宣告在這個class裡的區域變數
    this.brand=_brand
    this.year=_year
  }
  #speed = 0//因為acc要先在裡面吃speed，所以要先給speed值

  accelerate(acc){
    this.#speed += acc //#可以保護資料，不太容易被存取
  }
  

  echo(){
    console.log("Name："+this.name)
    console.log("Brand："+this.brand)
    console.log("Year："+this.year)
    console.log("Speed："+this.#speed)
  }
}

class MyJeep extends Mycar{ //繼承
  
  constructor(_name,_brand,_year,_spareTire){
    super(_name,_brand,_year)  //因為要對父物件裡的東西做擴充，故加上super()
    this.spareTire=_spareTire
  }

  spareTire=null
  
  echo(){
    super.echo()
    console.log("Spare Tire："+this.spareTire)
  }

}



