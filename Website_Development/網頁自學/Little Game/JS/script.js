let player=document.getElementById('player')
let playerBottom = parseInt(window.getComputedStyle(player).getPropertyValue('bottom'))
let playerRight = parseInt(window.getComputedStyle(player).getPropertyValue('right'))
let playerWidth = parseInt(window.getComputedStyle(player).getPropertyValue('width'))
let ground=document.getElementById('ground')
let groundBottom=parseInt(window.getComputedStyle(ground).getPropertyValue('bottom'))
let groundHeight=parseInt(window.getComputedStyle(ground).getPropertyValue('height'))
let displayScore=document.getElementById('Score')
let score=0

let isJumping=false
let uptime
let downtime

function jump(){
    if(isJumping) return
    uptime=setInterval(()=>{ //setInterval搭配代表每X毫秒更新一次，這裡是20毫秒
        if(playerBottom>=groundHeight+200){
            clearInterval(uptime) //停止setInterval計時器
            downtime=setInterval(()=>{
                if(playerBottom<=groundHeight+10){
                    clearInterval(downtime)
                    isJumping=false
                }
                playerBottom-=10
                player.style.bottom = playerBottom + 'px'
            },20)
        }
        playerBottom+=10
        player.style.bottom = playerBottom + 'px'
        isJumping=true
    },20)
}
function Score(){
    score+=1
    displayScore.innerText=`Score：${score}`
}
setInterval(Score,100)
function generateObstacle(){
    let obstacles=document.querySelector('.obstacles')
    let obstacle=document.createElement('div')
    obstacle.setAttribute('class','obstacle')
    obstacles.appendChild(obstacle)
    let randomTimeout=Math.floor(Math.random()*1000)+1000

    let obstacleBottom=150
    let obstacleWidth=30
    let obstacleRight=-30
    let obstacleHeight=Math.floor(Math.random()*50)+100
    obstacle.style.backgroundColor=`rgb(${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)},${Math.floor(Math.random()*255)})`

    

    function ObstacleMove(){
        obstacleRight+=5
        obstacle.style.right=obstacleRight+'px'
        obstacle.style.width=obstacleWidth+'px'
        obstacle.style.bottom=obstacleBottom+'px'
        obstacle.style.height=obstacleHeight+'px'
        if (playerBottom <= obstacleBottom + obstacleHeight && //從右邊往回看
            playerRight >= obstacleRight - playerWidth &&
            playerRight <= obstacleRight + obstacleWidth
            ){
                alert(`Game Over\n Your score：${score-1}`)
                clearInterval(obstacleInterval)
                clearTimeout(obstacleTimeout)
                console.log('hit')
                location.reload()
                clearInterval(Score)
            }
    }
    let obstacleInterval=setInterval(ObstacleMove,5)
    let obstacleTimeout=setTimeout(generateObstacle,randomTimeout) //會在1秒後執行

    

}
generateObstacle()
function control(i){
    if(i.key=='ArrowUp'||i.key==' '){
        jump()
    }
}
document.addEventListener('keydown',control)

    
