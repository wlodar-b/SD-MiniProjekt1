import matplotlib.pyplot as plt
import pandas as pd
import os

# Wczytanie pliku z pomiarami
try:
    with open('pomiary.txt', 'r') as f:
        content = f.read()
except FileNotFoundError:
    print("Brak pliku pomiary.txt w folderze!")
    exit()

# Parsowanie danych
blocks = content.split('========================================')
data = []

for block in blocks:
    lines = [l.strip() for l in block.strip().split('\n') if l.strip()]
    if len(lines) < 3:
        continue
    
    struktura = lines[0].split(': ')[1]
    rozmiar = int(lines[1].split(': ')[1])
    
    # Wyciąganie operacji (od 3 linijki w dół)
    for line in lines[3:]:
        if ': ' in line:
            op, time_str = line.split(': ')
            time = int(time_str.replace(' ns', '').strip())
            data.append({'Struktura': struktura, 'Rozmiar': rozmiar, 'Operacja': op, 'Czas': time})

df = pd.DataFrame(data)

# Tworzenie folderu na wyniki
os.makedirs('wykresy', exist_ok=True)
operacje = df['Operacja'].unique()

print("Generowanie wykresów...")

# Generowanie osobnego wykresu dla każdej operacji
for op in operacje:
    df_op = df[df['Operacja'] == op]
    
    plt.figure(figsize=(10, 6))
    
    for struktura in df['Struktura'].unique():
        df_struct = df_op[df_op['Struktura'] == struktura].sort_values('Rozmiar')
        if not df_struct.empty:
            plt.plot(df_struct['Rozmiar'], df_struct['Czas'], marker='o', linewidth=2, label=struktura)
            
    plt.title(f'Czas wykonywania operacji: {op}', fontsize=14)
    plt.xlabel('Rozmiar struktury (N)', fontsize=12)
    plt.ylabel('Średni czas [ns]', fontsize=12)
    plt.legend(title="Struktura danych")
    plt.grid(True, linestyle='--', alpha=0.7)
    
    # Prowadząca radzi: Jeśli widać, że punkty leżą na sobie z powodu skali (np. przy addStart)
    # plt.yscale('log') # Odkomentuj tę linię, jeśli dany wykres jest nieczytelny w skali liniowej
    
    # Zapis do pliku .png
    safe_op_name = op.replace('(', '_').replace(')', '')
    plt.savefig(f'wykresy/{safe_op_name}.png', dpi=300, bbox_inches='tight')
    plt.close()

print("Gotowe! Wykresy zapisano jako pliki .png w folderze 'wykresy'.")