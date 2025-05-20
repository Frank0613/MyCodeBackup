window.addEventListener('DOMContentLoaded', function() {
    var toggleButtons = document.getElementsByClassName('morebtm');
  
    function toggleText() {
      var button = this;
      if (button.innerText === '閱讀全文>') {
        button.innerText = '收起內容>';
      } else {
        button.innerText = '閱讀全文>';
      }
    }
  
    for (var i = 0; i < toggleButtons.length; i++) {
      toggleButtons[i].addEventListener('click', toggleText);
    }
  });