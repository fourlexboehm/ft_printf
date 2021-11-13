t_print *ft_initialise_tab(t_print *tab)
{
      tab->wdt = 0;
      tab->prc = 0;
      tab->zero = 0;
      tab->pnt = 0;
      tab->sign = 0;
      tab->tl = 0;
      tab->is_zero = 0;
      tab->dash = 0;
      tab->perc = 0;
      tab->sp = 0;
      return (tab);

}
int ft_printf(const char *format, ...)
{
   t_print *tab;

   tab = (t_print *)malloc(sizeof(t_print));
   if (!tab
       return (-1);
   ft_initialise_tab(tab)
}
