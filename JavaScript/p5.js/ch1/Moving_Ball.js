var balls = []

function setup(){
    createCanvas(800,800)
    //ball = new Ball(400, 400, 1, 1)
}

function draw(){
    background(0,0,0)
    //ball.draw()
    balls.forEach(ball=>{
        ball.draw()
    })
    
}
function mouseClicked() {
    balls.push(new Ball(400, 400, random(5,-5), random(5,-5))) 
}


class Ball{
    constructor(x, y, speedX, speedY){
        this.x = x
        this.y = y
        this.speedX = speedX
        this.speedY = speedY
    }

    draw(){
        this.x += this.speedX
        this.y += this.speedY
        //this.x = (this.x + width) % width
        //this.y = (this.y + height) % height
        if(this.x>width||this.x<0){
            this.speedX=-this.speedX
        }
        if(this.y>height||this.y<0){
            this.speedY=-this.speedY
        }
        circle(this.x, this.y, 15)
    }
}