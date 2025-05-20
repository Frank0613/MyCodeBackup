import gradio as gr #Docs：https://www.gradio.app/docs/interface

def color(text):
    return f"<div style='display: flex;'><p style='margin-right:10px; width:100px;'>#F023AC</p><div style='background-color:#F023AC; width:500px; height:20px;'></div></div>"

demo = gr.Interface(
    fn = color, #函式
    inputs='text', #輸入端類型
    outputs='html', #輸出端類型
    title='標題',
    description='內容',
    allow_flagging='never' #隱藏flag按鈕
)

demo.launch()