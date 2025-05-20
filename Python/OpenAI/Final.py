import openai as AI
from dotenv import dotenv_values
import gradio as gr
import json

file = dotenv_values('.env')
AI.api_key=file['Api_Key']


def generate_color(text):
    Question = f"""
    根據以下文字產生3到5個相關的顏色

    輸出格式 : python列表, 列表的值是16進制的顏色編碼

    ###
    google
    ###
    ["#4285F4", "#34A853", "#FBBC05", "#EA4335"]

    ###
    facebook
    ###
    ["#4267B2", "#3B5998"]

    ###
    {text}
    ###

  """ 
    data = AI.Completion.create( 
        model = 'gpt-3.5-turbo-instruct',
        max_tokens = 200,
        prompt = Question,
        stop = '', #出現甚麼字要停止生成
        n=1, #生成幾次
        echo = False #要不要重複問題(不會消耗Token)
        #參數設定：https://platform.openai.com/docs/api-reference/completions/create
    )
    result = json.loads(data['choices'][0]['text'])
    html = ""
    for color in result:
        html += f"<div style='display: flex; justify-content:center;'><p style='width:50px; height:22.75px; margin-right:15px;'>{color}</p><div style='background-color:{color}; width:500px; height:20px;'></div></div>"
    return html

demo = gr.Interface(
    fn = generate_color, #函式
    inputs='text', #輸入端類型
    outputs='html', #輸出端類型
    title='顏色產生器',
    description='輸入一段文字產生3~5個顏色',
    allow_flagging='never' #隱藏flag按鈕
)

demo.launch()




