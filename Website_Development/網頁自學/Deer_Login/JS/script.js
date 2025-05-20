const wrapper=document.querySelector('.wrapper');//document是JS連接HTML的橋樑，querySelector可以選取HTML裡所有.wrapper標籤，並存入wrapper變量
const loginlink=document.querySelector('.logintext');
const registerlink=document.querySelector('.registertext');
const loginbtmDown=document.querySelector('.loginbtm');
const CloseIcon=document.querySelector('.close-icon');

registerlink.addEventListener('click',()=>{ //addEventListener是事件監聽器，當click之後會觸發匿名函數回傳
    wrapper.classList.add(('active')); //這是在wrapper的類別裡加入active
})

loginlink.addEventListener('click',()=>{ //addEventListener是事件監聽器，當click之後會觸發匿名函數回傳
    wrapper.classList.remove(('active')); //這是在wrapper的類別裡加入active
})

loginbtmDown.addEventListener('click',()=>{ //addEventListener是事件監聽器，當click之後會觸發匿名函數回傳
    wrapper.classList.add(('loginbtm-Down')); //這是在wrapper的類別裡加入active
})
CloseIcon.addEventListener('click',()=>{ //addEventListener是事件監聽器，當click之後會觸發匿名函數回傳
    wrapper.classList.remove(('loginbtm-Down')); //這是在wrapper的類別裡加入active
})



























