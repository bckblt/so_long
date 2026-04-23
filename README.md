# so_long

MiniLibX ile yapılmış 2D top-down bir oyun — 42 İstanbul projesi.

## Oyun

Oyuncu tüm koleksiyonları toplayıp çıkışa ulaşmaya çalışır. Her hareket sayılır ve ekranda gösterilir.

- `W A S D` veya ok tuşları → hareket
- `ESC` → çıkış

## Map Sembolleri

| Sembol | Anlam      |
|--------|------------|
| `1`    | Duvar      |
| `0`    | Boş zemin  |
| `P`    | Oyuncu     |
| `C`    | Koleksiyon |
| `E`    | Çıkış      |

## Kullanım

```bash
make
./so_long maps/map.ber
```

## Teknolojiler

`MiniLibX` · `get_next_line` · `ft_printf` · `2D tilemap` · C

---

**bakarabu** — 42 İstanbul
