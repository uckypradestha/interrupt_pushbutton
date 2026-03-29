<h2>INTERRUPT DENGAN PUSH BUTTON</h2>

<p>Untuk membuat sebuah interrupt, pertama-tama kamu perlu menulis fungsi khusus yang disebut interrupt service routine (ISR). ISR ini akan berisi semua kode yang ingin dijalankan ketika interrupt dipicu.

Pada contoh LED berkedip sebelumnya, kita ingin agar penekanan tombol dapat mengontrol LED merah sementara LED kuning terus berkedip menyala dan mati. Oleh karena itu, pilihan yang logis adalah menjadikan penekanan tombol sebagai pemicu interrupt.

Pada sketch di atas, terdapat sebuah ISR untuk penekanan tombol yang bernama buttonInterrupt(). Di dalam ISR tersebut terdapat kode yang membaca buttonPin dan menghidupkan atau mematikan LED merah.</p>

<h2>Konfigurasi Pin</h2>
<ul>
    <li>LED Kuning ------- Pin 12</li>
    <li>LED Merah -------- Pin 11</li>
    <li>Push Button ------ Pin 2</li>
</ul>