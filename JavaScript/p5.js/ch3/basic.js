function setup() {
    createCanvas(400, 400);
    console.log(lerp(50,300,0.5)) //線性插植
    console.log(Norm(300,100,500)) 
    console.log(map(300,100,500,50,300))//映射
  
    console.log(constrain(-50,0,100))//-50不在0~100間，所以輸出0
    console.log(constrain(50,0,100))//50在0~100間，所以輸出50
    console.log(constrain(150,0,100))//150在0~100間，所以輸出150
  
    console.log(lerp(100,200,constrain(0.5,0,1))) //防止lerp值大於1
  
  
  }
  
  function draw() {
    background(220);
  }
  function lerp(a,b,t){  
    return a+(b-a)*t
  }
  function Norm(v,a,b){
    return (v-a)/(b-a)
  }
  function map(o1,o2,v,n1,n2){
    return n1+(n2-n1)*n(v,o1,o2) //lerp(n1,n2,norm(v,o1,o2))
  }
  
  
  
  
  
  