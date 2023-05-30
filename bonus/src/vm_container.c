/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** VM container
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "demo.h"
#include "ui_panels/slider.h"

vm_container_t *vm_container_create(program_t *p, vm_t *vm)
{
    vm_container_t *vmc = NULL;
    panel_t *control = p->scenes[1]->canvas->panels[0]->childs[0]->childs[0]->childs[0];

    vmc = malloc(sizeof(vm_container_t));
    if (!vmc)
        return NULL;
    vmc->vm = vm;
    vmc->vmflex = p->scenes[1]->canvas->panels[0]->childs[0]->childs[2];
    vmc->winpanel = p->scenes[1]->canvas->panels[0]->childs[0]->childs[1];
    vmc->seconds = 0;
    vmc->timescale = 0;
    ((panel_slider_t *)(control->childs[3]->childs[1]->childs[1]->data))->trgt = vmc;
    vmc->timescaleText = control->childs[3]->childs[0]->childs[1]->text;
    vmc->champ1text = control->childs[0]->childs[0]->childs[1]->text;
    sfText_setColor(control->childs[0]->childs[0]->childs[0]->text, COLOR1);
    sfText_setString(control->childs[0]->childs[0]->childs[0]->text, vm->process->id);
    vmc->champ2text = control->childs[0]->childs[1]->childs[1]->text;
    sfText_setColor(control->childs[0]->childs[1]->childs[0]->text, COLOR2);
    sfText_setString(control->childs[0]->childs[1]->childs[0]->text, vm->process->next->id);
    if (vm->nb_champ > 2) {
        vmc->champ3text = control->childs[1]->childs[0]->childs[1]->text;
        sfText_setColor(control->childs[1]->childs[0]->childs[0]->text, COLOR3);
        sfText_setString(control->childs[1]->childs[0]->childs[0]->text, vm->process->next->next->id);
    }
    if (vm->nb_champ > 3) {
        vmc->champ4text = control->childs[1]->childs[1]->childs[1]->text;
        sfText_setColor(control->childs[1]->childs[1]->childs[0]->text, COLOR4);
        sfText_setString(control->childs[1]->childs[1]->childs[0]->text, vm->process->next->next->next->id);
    }
    control = control->childs[2];
    vmc->cycleText = control->childs[0]->childs[1]->text;
    vmc->totalcycleText = control->childs[1]->childs[1]->text;
    vmc->nblivetext = control->childs[2]->childs[1]->text;
    return vmc;
}

void vm_container_destroy(vm_container_t *vmc)
{
    free_thevm(vmc->vm);
    free(vmc);
}

void update_text(sfText *text, const char *str)
{
    sfFloatRect trect;

    sfText_setString(text, str);
    trect = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
}

void vm_stats_update(vm_container_t *vmc)
{
    char str[20] = {0};
    sprintf(str, "%i", vmc->vm->cycle);
    update_text(vmc->totalcycleText, str);
    sprintf(str, "%i / %i", vmc->vm->cycle, vmc->vm->cycle_to_die);
    update_text(vmc->cycleText, str);
    sprintf(str, "%i / %i", vmc->vm->nb_alive, NBR_LIVE);
    update_text(vmc->nblivetext, str);
}

void vm_champ_update(vm_container_t *vmc)
{
    int count[4] = {0, 0, 0, 0};
    process_t *proc = vmc->vm->process;
    char str[10] = {0};

    while (proc) {
        count[proc->nb_champ - 1]++;
        proc = proc->next;
    }
    sprintf(str, "%i", count[0]);
    update_text(vmc->champ1text, str);
    sprintf(str, "%i", count[1]);
    update_text(vmc->champ2text, str);
    if (vmc->vm->nb_champ <= 2)
        return;
    printf("champ3\n");
    sprintf(str, "%i", count[2]);
    update_text(vmc->champ3text, str);
    if (vmc->vm->nb_champ <= 3)
        return;
    printf("champ4\n");
    sprintf(str, "%i", count[3]);
    update_text(vmc->champ4text, str);
}

void vmflex_update(vm_container_t *vmc)
{
    int i = 0;
    char hexa[] = "OO";
    const char hexadict[] = "O123456789ABCDEF";
    unsigned char tmp = 0;

    for (; i < MEM_SIZE && vmc->vmflex->childs[i]; i++) {
        tmp = vmc->vm->memory[i];
        hexa[0] = hexadict[tmp / 16];
        hexa[1] = hexadict[tmp % 16];
        sfText_setString(vmc->vmflex->childs[i]->text, hexa);
        switch (vmc->vm->ownership[i]) {
            case 1:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR1);
                break;
            case 2:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR2);
                break;
            case 3:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR3);
                break;
            case 4:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR4);
                break;
        }
    }
}

void vmproc_update(vm_container_t *vmc)
{
    process_t *proc = vmc->vm->process;

    while (proc) {
        if (proc->index == - 1) {
            proc = proc->next;
            continue;
        }
        for (int i = 0; i < MEM_SIZE; i++) {
            if (proc->index == i) {
                sfText_setColor(vmc->vmflex->childs[i]->text, sfWhite);
                break;
            }
        }
        proc = proc->next;
    }
}

static int incre_cycle(int cycle_to_die, vm_t *vm)
{
    if (vm->nb_alive >= NBR_LIVE) {
        cycle_to_die -= CYCLE_DELTA;
        vm->nb_alive = 0;
    }
    return cycle_to_die;
}

char *get_endwinner(process_t *list_champ)
{
    process_t *winner = NULL;
    process_t *current = list_champ;
    int last_live = 0;

    if (current != NULL) {
        last_live = current->last_lives;
    }
    while (current) {
        if (current->last_lives <= last_live) {
            winner = current;
            last_live = current->last_lives;
        }
        current = current->next;
    }
    if (winner != NULL) {
        return winner->id;
    }
    return NULL;
}

int vm_container_update(vm_container_t *vmc, float seconds)
{
    int ret = 0;
    vmc->seconds += seconds * vmc->timescale;
    while (vmc->seconds >= 1.0 / CYCLE_PER_SEC) {
        vmc->seconds -= 1.0 / CYCLE_PER_SEC;
        if (vmc->vm->cycle_to_die <= 0 || vmc->vm->champ_alive <= 1 || vmc->vm->f_dump == 0) {
            ret = -1;
            break;
        }
        loop_process(vmc->vm, vmc->vm->process, vmc->vm->cycle_to_die);
        vmc->vm->cycle++;
        if (vmc->vm->f_dump > 0)
            vmc->vm->f_dump--;
        if (vmc->vm->cycle == vmc->vm->cycle_to_die) {
            vmc->vm->cycle_to_die = incre_cycle(vmc->vm->cycle_to_die, vmc->vm);
            vmc->vm->cycle = 0;
        }
        vmc->vm->champ_alive = get_nb_champ_alive(vmc->vm->process, vmc->vm);
    }
    if (ret == -1) {
        update_text(vmc->winpanel->text, get_endwinner(vmc->vm->process));
    }
    vm_stats_update(vmc);
    vm_champ_update(vmc);
    vmflex_update(vmc);
    vmproc_update(vmc);
    return ret;
}