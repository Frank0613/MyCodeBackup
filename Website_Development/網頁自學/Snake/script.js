var board
var blocksize = 25
var rows = 20
var cols = 20
var context

window.onload = function(){ //當網頁加載完畢後，就會執行 function()
    board = document.getElementById('board')
    board.height = rows * blocksize
    board.width = cols * blocksize
    context = board.getContext('2d')//渲染2d畫布內容

    Update()
} 

function Update(){
    context.fillStyle='black'
    context.fillRect(0,0,board.width,board.height)//繪製矩形(前面兩個是起始點座標,矩形的寬度和高度)
}