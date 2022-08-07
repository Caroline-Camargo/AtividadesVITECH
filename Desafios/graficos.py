#Script que acessa o arquivo av1_20.csv e cria gráfico com as frequencias do código

import matplotlib.pyplot as plt
import numpy as np 


#Abrindo arquivo:
tabela = open("csvs - tamanho de bloco/touchdown_pass_1080p_60f/av1_55.csv", "r") 
    
#Váriaveis
x=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21] 
frequencias = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

matriz_tabela=[]
num_linhas_matriz=0
primeira_linha=1

#Obtendo dados do arquivo
for linha in tabela:   
    if(primeira_linha==1): #Linha 1 não precisa ser lida
        primeira_linha+=1
    else:
        dados = linha
        dados = dados.split(',') #separa dados por , 
        
        #testes para saber a frequencia do código
        if ("0" == dados[3]):
            frequencias[0]+=1
        if ("1" == dados[3]):
            frequencias[1]+=1
        if ("2" == dados[3]):
            frequencias[2]+=1
        if ("3" == dados[3]):
            frequencias[3]+=1
        if ("4" == dados[3]):
            frequencias[4]+=1
        if ("5" == dados[3]):
            frequencias[5]+=1
        if ("6" == dados[3]):
            frequencias[6]+=1
        if ("7" == dados[3]):
            frequencias[7]+=1
        if ("8" == dados[3]):
            frequencias[8]+=1
        if ("9" == dados[3]):
            frequencias[9]+=1
        if ("10" == dados[3]):
            frequencias[10]+=1
        if ("11" == dados[3]):
            frequencias[11]+=1
        if ("12" == dados[3]):
            frequencias[12]+=1
        if ("13" == dados[3]):
            frequencias[13]+=1
        if ("14" == dados[3]):
            frequencias[14]+=1
        if ("15" == dados[3]):
            frequencias[15]+=1
        if ("16" == dados[3]):
            frequencias[16]+=1
        if ("17" == dados[3]):
            frequencias[17]+=1
        if ("18" == dados[3]):
            frequencias[18]+=1
        if ("19" == dados[3]):
            frequencias[19]+=1
        if ("20" == dados[3]):
            frequencias[20]+=1
        if ("21" == dados[3]):
            frequencias[21]+=1   
            
tabela.close()

#Montando Gráfico
plt.figure(figsize=(10,5)) #aumenta tamanho do gráfico
plt.bar(x,frequencias, label = 'Ocorrencias dos códigos de \ntamanho de bloco do AV1', color='red')

#legendas
plt.xlabel("Códigos") 
plt.ylabel("Frequências") 
plt.xticks(np.arange(22), x)  # Legenda eixo X 
plt.title("CQ: 55       VÍDEO: touchdown_pass_1080p_60f") 
plt.legend()

cont=0
while (cont < len(x)): #mostrando valor de cada barra do gráfico
    if (frequencias[cont]!=0):#apenas para os valores diferentes de zero
        plt.text(cont-0.5, frequencias[cont]+500, frequencias[cont], color = 'blue') 
    cont+=1
    
plt.savefig('grafico_cq55_touchdown_pass_1080p_60f.png') #Salvar imagem do gráfico no computador 

plt.show()

    
    
