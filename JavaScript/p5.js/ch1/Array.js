function setup(){
//陣列
const arr = ["apple","banana","orange"] //const代表arr不可以被修改，但arr裡的值可以
//arr=[1,2,3] 這樣會錯誤
console.log(arr[0])
console.log(arr[-1])//代表從最後面數
console.log(arr.length)//計算長度
console.log(arr.indexOf("orange"))//找索引值

arr.push("grape")//從最後面插入元素
arr.pop("grape")//從最後面刪除元素

value=arr.shift()//從最前面刪除元素，然後把刪除的東西加入value
console.log(value)//印出刪除的東西
value=arr.unshift("cat")//從最前面加入元素，然後把加入的東西加入value
console.log(value)//印出加入的東西

const arr1=[1,2,3]
const arr2=[4,5,6]
const arr3=arr1.concat(arr2)//把陣列1和陣列2接在一起=>[1,2,3,4,5,6]

const arr4=[1,2,3,4,5,6]
console.log(arr.slice(2)) //從第二個開始往後印(包括第二個)
console.log(arr.slice(2,5)) //前面是起點後面是終點，從第二個開始到第五個(不包括第五個)
console.log(arr.slice(2,-1)) //從第二個開始到倒數第1個(不包括倒數第1個)
console.log(arr.slice(-2)) //會印出[5,6]，因為從倒數第二開始
//起點包含，終點不包含

const arr5=[1,2,3,4,5,6]
arr5.forEach((element)=>{console.log(element)}) //會對每個元素執行列印



}
function draw(){



}