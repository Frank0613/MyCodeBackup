let text=document.getElementById('text');
let leftTree=document.getElementById('tree-left');
let rightTree=document.getElementById('tree-right');
let leftgate=document.getElementById('gate-left');
let rightgate=document.getElementById('gate-right');

window.addEventListener('scroll',()=>{
    let value=window.scrollY //設定一個value存取視窗滾動的Y值
    text.style.marginTop = value*1.5 + 'px'; //新增一個<style>在Html裡'text'id的後面，並設定marginTop為滾動的value
    leftTree.style.left=value*-0.5+'px'
    rightTree.style.left=value * 0.5+'px'
    leftgate.style.left=value*0.5+'px'
    rightgate.style.left=-value*0.5+'px'

});