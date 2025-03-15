import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# Define the data
data = {
    "Test #": [1, 2, 3, 4, 5, 6, 7],
    "Polyphony": ["1 voice", "2 voices", "4 voices", "4 voices", "8 voices", "8 voices", "8 voices"],
    "Frequency (Hz)": [440, 880, 1000, 200, 500, 2000, 440],
    "Waveform Type": ["Sine", "Square", "Sawtooth", "Triangle", "Sine", "Square", "Sine"],
    "Output Amplitude (Vpp)": [1.2, 2.0, 2.8, 3.2, 2.5, 3.0, 3.2],
    "Measured THD (%)": [0.002, 0.006, 0.010, 0.008, 0.012, 0.015, 0.018],
    "Measured SNR (dB)": [112, 109, 106, 108, 105, 102, 100],
    "Sample Rate (kHz)": [44.1, 44.1, 44.1, 44.1, 44.1, 44.1, 44.1],
    "CPU Usage (%)": [25, 30, 45, 50, 65, 70, 72],
    "Observations / Notes": [
        "Clean single note; low noise floor",
        "Slight distortion at higher harmonics",
        "Noticeable increase in harmonic content",
        "Max amplitude test; stable but some clipping",
        "Poly mode introduces slightly more noise",
        "Audible distortion at higher frequency",
        "Maximum amplitude at 8 voices"
    ]
}

# Create a DataFrame
df = pd.DataFrame(data)

# Convert Polyphony column to numeric values (if needed)
df['Polyphony_Num'] = df['Polyphony'].str.extract('(\d+)').astype(int)

# Calculate overall averages for THD and SNR
avg_thd = np.mean(df["Measured THD (%)"])
avg_snr = np.mean(df["Measured SNR (dB)"])

# Set seaborn style for consistency
sns.set(style="whitegrid", context="talk")

# -------------------------------
# Plot 1: THD vs Frequency
# -------------------------------
plt.figure(figsize=(10, 7))
sns.regplot(
    x="Frequency (Hz)", y="Measured THD (%)",
    data=df, scatter=True,
    scatter_kws={'s':100, 'edgecolor':'k'},
    line_kws={'color':'red', 'lw':2},
    ci=None  # Do not show confidence interval
)
plt.axhline(avg_thd, color="blue", linestyle="--", lw=2, label=f"Avg THD = {avg_thd:.4f}")
plt.title("Measured THD vs Frequency")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Measured THD (%)")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.6)
plt.tight_layout()
plt.savefig("synth_performance_thd.png", dpi=300)
plt.close()  # Close the figure

# -------------------------------
# Plot 2: SNR vs Frequency
# -------------------------------
plt.figure(figsize=(10, 7))
sns.regplot(
    x="Frequency (Hz)", y="Measured SNR (dB)",
    data=df, scatter=True,
    scatter_kws={'s':100, 'edgecolor':'k'},
    line_kws={'color':'red', 'lw':2},
    ci=None  # Do not show confidence interval
)
plt.axhline(avg_snr, color="blue", linestyle="--", lw=2, label=f"Avg SNR = {avg_snr:.1f} dB")
plt.title("Measured SNR vs Frequency")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Measured SNR (dB)")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.6)
plt.tight_layout()
plt.savefig("synth_performance_snr.png", dpi=300)
plt.close()

print("Two plots have been saved as 'synth_performance_thd.png' and 'synth_performance_snr.png'.")
